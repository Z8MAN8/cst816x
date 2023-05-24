# CST816X

## 简介

cst816x 软件包提供了使用触摸芯片 cst816x 基本功能，并且本软件包已经对接到了 Touch 框架，通过 Touch 框架，开发者可以快速的将此触摸芯片驱动起来。
## 支持情况

| **CST816X 触摸芯片** | **支持情况** |
| :-------: | :--------: |
| I2C 通讯接口 | √ |
| 轮询的工作模式 | √ |

## 使用说明

### 软件包依赖

- RT-Thread 4.0.0+
```
 \ | /
- RT -     Thread Operating System
 / | \     5.0.1 build May 24 2023 00:35:23
 2006 - 2022 Copyright by RT-Thread team
 msh >
```
- Touch 组件，在 menuconfig 中开启 Touch 组件的路径如下：
```
RT-Thread Components  --->
    Device Drivers  --->
        [*] Using Touch device drivers
```
- I2C 驱动：cst816x 设备使用 I2C 进行数据通讯，需要系统 I2C 驱动支持，在 menuconfig 中开启 I2C 驱动的路径如下：
```
Hardware Drivers Config  --->
    On-chip Peripheral Drivers  --->
        [*] Enable I2C0 BUS  --->
```

### 获取软件包

使用 cst816x 软件包需要在 RT-Thread 的包管理中选中它，具体路径如下：

```
RT-Thread online packages  --->
    peripheral libraries and drivers  --->
      touch drivers  --->
        cst816x : touch ic cst816x for rt-thread
          Version (latest)  --->
```
配置完成后，使用 `pkgs --update` 更新软件包。

### 使用软件包

cst816x 软件包初始化函数如下所示：

```
int rt_touch_init(void)
```

该函数需要由用户调用，函数主要完成的功能有：

- 设备配置和初始化（配置接口设备和中断引脚）；
- 注册相应的传感器设备，完成 touch 设备的注册；

#### 初始化示例

```.c
#define TOUCH_I2C_NAME "i2c0"
#define TOUCH_RST_PIN  (24)
#define TOUCH_INT_PIN  (32)
INIT_ENV_EXPORT(rt_touch_init);
```

## 注意事项

- 该软件包目前仅提供一个触点
- 在初始化示例中，需要根据自己板子上的实际连接情况，修改 I2C 的设备名和 cst816x 的中断引脚和 RST 引脚

## 联系人信息

- 维护人：[Z8MAN8](https://github.com/Z8MAN8)
- 软件包主页：<https://github.com/Z8MAN8/cst816x>