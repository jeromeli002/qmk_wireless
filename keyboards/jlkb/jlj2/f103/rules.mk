MAKEFLAGS= -j 16 # 设置并行编译的作业数，这里设置为 16，加快编译速度

# 禁用不支持的硬件 (Disable unsupported hardware)
AUDIO_SUPPORTED = no # 禁用音频支持
BACKLIGHT_SUPPORTED = no # 禁用背光支持

BOOTMAGIC_ENABLE = yes   # 启用 Bootmagic Lite (轻量级引导恢复功能)
KEYBOARD_SHARED_EP = yes # 共享端点，释放额外端点 - 如果需要 console+mouse+extra 则需要
MOUSEKEY_ENABLE = yes    # 启用鼠标按键功能
EXTRAKEY_ENABLE = yes    # 启用额外的按键功能 (例如音量控制和系统控制)
CONSOLE_ENABLE = no      # 禁用调试控制台
COMMAND_ENABLE = no      # 禁用调试和配置命令

# 请勿启用 SLEEP_LED_ENABLE。它使用与 BACKLIGHT_ENABLE 相同的定时器 (Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE)
SLEEP_LED_ENABLE = no    # 禁用睡眠 LED (在 USB 挂起期间呼吸闪烁)

# 如果此项不起作用，请参阅此处：https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work (if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work)
NKRO_ENABLE = yes        # 启用 USB N 键翻转 (无限制同时按下)
BACKLIGHT_ENABLE = no    # 禁用键盘背光功能
# ENCODER_ENABLE = yes     # 启用旋转编码器支持
# ENCODER_MAP_ENABLE = yes # 启用旋转编码器映射
AUDIO_ENABLE = no      # 禁用音频输出
SPLIT_KEYBOARD = no    # 禁用分体键盘支持

# SERIAL_DRIVER = usart # 串口驱动
RGBLIGHT_ENABLE ?= yes # RGB 灯带支持
# RGB_MATRIX_ENABLE = yes # RGB 矩阵支持
# RGB_MATRIX_DRIVER = WS2812 # RGB 矩阵驱动
# WS2812_DRIVER = pwm # WS2812 驱动方式
# WPM_ENABLE = yes      # 显示 APM (每分钟按键次数)
DYNAMIC_MACRO_ENABLE = yes # 启用动态宏

# POINTING_DEVICE_ENABLE = yes      # 摇杆模拟指点杆
# POINTING_DEVICE_DRIVER = analog_joystick # 摇杆模拟指点杆驱动
# JOYSTICK_TRIGGER_ENABLE = yes # 摇杆映射按键
# JOYSTICK_ENABLE = yes        # 启用游戏摇杆/映射按键
# JOYSTICK_DRIVER = analog # 摇杆驱动

# 在 ChibiOS 空闲线程上进入低功耗睡眠模式 (Enter lower-power sleep mode when on the ChibiOS idle thread)
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# 可编程按键 (Programmable Button)
PROGRAMMABLE_BUTTON_ENABLE = yes

# OLED 屏幕开关 (OLED screen switch)
# OLED_ENABLE = yes # 启用 OLED 屏幕
# OLED_DRIVER = ssd1306    # OLED 驱动

EXTRAFLAGS+=-flto # 如果固件太大，在 rule.mk 中添加 EXTRAFLAGS+=-flto，启用链接时优化

# VPATH += keyboards/jlkb/jllab/ # 指定源文件搜索路径，建议在键盘的 rules.mk 中设置