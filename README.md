# PS2无线手柄驱动
## 概要
自制PS2手柄驱动程序，采用STM32F103C8T6开发板搭建转接器，使用STM32CubeMX生成主程序
## 内容
### 通讯
由于USB需要48MHz的时钟频率，PS2手柄使用硬件SPI需要64MHz时钟频率，不能同时满足，所以用了软件SPI模拟
### 键位
自行查阅资料配置而成，与现代PS手柄采用相同方案
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
  - Middlewares USB相关，由CubeMX生成，其中USB传输报文由HID Descriptor Tool生成
  - USB_DEVICE USB相关，由CubeMX生成
- PS2_USB_TEST.ioc CubeMX工程文件，可供参考
