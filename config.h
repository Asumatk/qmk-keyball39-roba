#pragma once

// roBa(ZMK) の mt: flavor="balanced", quick-tap-ms=0 に近い挙動
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0

// コンボ: 同時押しとみなす時間(ms)。どのレイヤーでもレイヤー0のキー位置で判定（roBaと同じ）
#define COMBO_TERM 50
#define COMBO_ONLY_FROM_LAYER 0

// レイヤー数 8 (0-7)
#define LAYER_STATE_8BIT

#define TAP_CODE_DELAY 5

// トラックボールを動かすと自動で MOUSE レイヤー(4) に入る（roBaと同じ）
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 4
