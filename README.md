# ft_printf

A custom implementation of the C standard library printf function with support for basic format specifiers and flags.

## Overview

This project recreates printf's core functionality without using the buffer management of the original printf. It handles the most common format specifiers and formatting flags.

## Features

### Format Specifiers

| Specifier | Description |
|-----------|-------------|
| %c | Single character |
| %s | String of characters |
| %p | Pointer address in hex |
| %d | Decimal (base 10) integer |
| %i | Integer in base 10 |
| %u | Unsigned decimal integer |
| %x | Hex integer (lowercase) |
| %X | Hex integer (uppercase) |
| %% | Percent sign |

### Flags

| Flag | Description |
|------|-------------|
| - | Left-justify within field width |
| + | Force plus/minus sign |
| (space) | Space if no sign |
| # | 0x/0X prefix for hex |
| 0 | Zero padding |
| . | Precision |
| width | Minimum field width |

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    // Basic string
    ft_printf("Hello %s!\n", "world");
    
    // Multiple formats
    ft_printf("Num: %d, Hex: %x, Char: %c\n", 42, 42, 'A');
    
    // Using flags
    ft_printf("Padded: %05d\n", 42);
    ft_printf("Left-aligned: %-10s\n", "text");
    
    return (0);
}
```

## Notes

- Buffer management is not implemented as per project requirements
- All memory allocations are properly handled and freed
- The project follows 42 school's coding standards
