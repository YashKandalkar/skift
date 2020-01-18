#pragma once

/* Copyright © 2018-2019 N. Van Bossuyt.                                      */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <libsystem/runtime.h>
#include <libterminal/Color.h>

typedef struct
{
    TerminalColor foreground;
    TerminalColor background;

    bool bold;
    bool italic;
    bool underline;
} TerminalAttributes;

TerminalAttributes terminal_attributes_bold(TerminalAttributes attributes);

TerminalAttributes terminal_attributes_italic(TerminalAttributes attributes);

TerminalAttributes terminal_attributes_underline(TerminalAttributes attributes);

TerminalAttributes terminal_attributes_regular(TerminalAttributes attributes);

TerminalAttributes terminal_attributes_with_foreground(TerminalAttributes attributes, TerminalColor foreground);

TerminalAttributes terminal_attributes_with_background(TerminalAttributes attributes, TerminalColor background);

bool terminal_attributes_equals(TerminalAttributes left, TerminalAttributes right);