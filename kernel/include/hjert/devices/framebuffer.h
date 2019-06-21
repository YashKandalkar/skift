#pragma once

/* Copyright © 2018-2019 N. Van Bossuyt.                                      */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <skift/runtime.h>
#include <skift/shape.h>

#define FRAMEBUFFER_DEVICE "/dev/fb"
#define FRAMEBUFFER_IOCTL_SET_MODE 0
#define FRAMEBUFFER_IOCTL_GET_MODE 1
#define FRAMEBUFFER_IOCTL_BLIT 2
#define FRAMEBUFFER_IOCTL_BLITREGION 3

#define FRAMEBUFFER_CHANNEL "#dev:framebuffer"
#define FRAMEBUFFER_MODE_CHANGE "framebuffer.modechange"

typedef struct
{
    bool enable;

    int width;
    int height;
} framebuffer_mode_info_t;

typedef struct
{
    void *src;
    rectangle_t bound;
} framebuffer_region_t;
