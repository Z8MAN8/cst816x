/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author         Notes
 * 2023-5-23      Chushicheng    first version.
 */
/*
 * Program Listing: This is a touch device usage routine
 * The routine exports touch_sample commands to the control terminal
 * Command invocation format: touch_sample
 * Program function: detect touch points, and print touch point coordinates
*/

#include <rtthread.h>
#include <rtdevice.h>
#include "cst816x.h"

#ifdef PKG_USING_CST816X_SAMPLE

#define TOUCH_DEV_NAME  "touch"

static void touch_sample(void){
    char name[RT_NAME_MAX];
    rt_strncpy(name, TOUCH_DEV_NAME, RT_NAME_MAX);

    static rt_device_t dev = RT_NULL;
    static struct rt_touch_data *read_data;
    read_data = (struct rt_touch_data *)rt_malloc(sizeof(struct rt_touch_data));

    dev = rt_device_find(name);
    if (dev == RT_NULL)
    {
        rt_kprintf("can't find %s device!\n", name);
    }
    rt_device_open(dev, RT_DEVICE_FLAG_INT_RX);

    while(1){
        if(rt_pin_read(TOUCH_INT_PIN) == 0){ //if int pin is 0 was touched
            if(rt_device_read(dev, 0, read_data, 1)!=0){
            uint16_t pos_x = read_data->x_coordinate;
            uint16_t pos_y = read_data->y_coordinate;
            rt_kprintf("x: %d y:%d\r\n",pos_x,pos_y);
            }
        }

        rt_thread_mdelay(10);
    }
}
MSH_CMD_EXPORT(touch_sample, touch sample);

#endif  /* PKG_USING_CST816X_SAMPLE */
