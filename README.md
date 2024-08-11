# PS2无线手柄驱动
## 概要
自制PS2手柄驱动程序，采用STM32F103C8T6开发板搭建转接器，使用STM32CubeMX生成主程序
## 内容
### 通讯
由于USB需要48MHz的时钟频率，PS2手柄使用硬件SPI需要64MHz时钟频率，不能同时满足，所以用了软件SPI模拟
### 键位
数据内容包含于USB_Upload_data数组中，具体分配如下：
\[0\]位：左摇杆X轴，8位，范围0x00~0xFF
\[1\]位：左摇杆Y轴，8位，范围0x00~0xFF
\[2\]位：右摇杆X轴，8位，范围0x00~0xFF
\[3\]位：右摇杆Y轴，8位，范围0x00~0xFF
\[4\]位：8按键，每个按键1位，共8位，从右到左为**UP，DOWN，LEFT，RIGHT，Y，A，X，B**，对应按键编号1~8，以“上下左右”顺序分布
\[5\]位：8按键，每个按键1位，共8位，从右到左为**L1，R1，L2，R2，L3，R3，SELECT，START**，对应按键编号1~8
### 摇杆死区
当前版本设计为锥形区域，以X/Y轴偏离原点较远一轴为基准轴，死区坐标范围为**基准轴坐标/8**，具体解算过程可参照main.c中内容
### USB
由STM32CubeMX生成主程序，选用HID方案，具体报文由DT生成

## 使用
### 材料需求
#### 平常使用
- STM32F103C8T6开发板*1
- PS2手柄及配套接收器*1
- 杜邦线*6
#### 烧录程序
- 下载器*1
- 杜邦线若干

## 文件结构
- Core 单片机核心代码
- Drivers
  - CMSIS & STM32F1xx_HAL_Driver CubeMX自动配置，驱动文件
  - Software 软件驱动包
    - Delay 时延函数，参考自CSDN，[参考来源](https://blog.csdn.net/zhijianqifei/article/details/127796211)
    - PS2 手柄信息传输及处理，基于通信协议原创
    - SPI 软件SPI模拟程序，基于通信协议原创
  - MDK-ARM 单片机相关，由CubeMX生成
  - Middlewares USB相关，由CubeMX生成，其中USB传输报文由[HID Descriptor Tool](https://www.usb.org/document-library/hid-descriptor-tool)生成
  - USB_DEVICE USB相关，由CubeMX生成
- PS2_USB_TEST.ioc CubeMX工程文件，可供参考
