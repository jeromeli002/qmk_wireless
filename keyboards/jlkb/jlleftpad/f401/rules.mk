MAKEFLAGS= -j 16
# Build Options
#   change yes to no to disable
#
# MCU name
MCU = STM32F401
BOARD = BLACKPILL_STM32_F401

# Bootloader selection
BOOTLOADER = tinyuf2

# 启用/禁用不支持的硬件
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no
BOOTMAGIC_ENABLE = yes     # 启用 Bootmagic Lite
KEYBOARD_SHARED_EP = yes    # Free up some extra endpoints - needed if console+mouse+extra
MOUSEKEY_ENABLE = yes       # 鼠标键
EXTRAKEY_ENABLE = yes       # 音频控制和系统控制
CONSOLE_ENABLE = no         # 调试控制台
COMMAND_ENABLE = no         # 调试和配置命令
# 不要启用 SLEEP_LED_ENABLE。它使用与 BACKLIGHT_ENABLE 相同的计时器
SLEEP_LED_ENABLE = no       # USB 挂起期间呼吸睡眠 LED
# 如果这不起作用，请参见此处: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # 全键无冲
BACKLIGHT_ENABLE = no       # 启用键盘背光功能
ENCODER_ENABLE = yes        # 启用旋转编码器支持
ENCODER_MAP_ENABLE = yes    # 旋钮映射
AUDIO_ENABLE = no           # 音频输出
RGBLIGHT_ENABLE ?= yes
SPLIT_KEYBOARD = no
# SERIAL_DRIVER = usart
DYNAMIC_MACRO_ENABLE = yes  # 启用动态宏
# OLED_ENABLE = yes
# OLED_DRIVER = SSD1306    # 启用OLED屏幕
EXTRAFLAGS+=-flto  # 如果固件太大在rule.mk 中添加EXTRAFLAGS+=-flto 