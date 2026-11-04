/*
 * Keyball39 keymap — roBa (Asumatk/zmk-config-roBa) の配列を移植したもの
 *
 * roBaとの違い
 *  - roBaの中央寄り4キー（Win+Shift+S / - / : / ;）はKeyball39に無いため、コンボで代用
 *      F+G = Win+Shift+S,  H+J = -,  V+B = :,  N+M = ;
 *  - 他レイヤーの中央寄りキーで行き場が無くなったものは、空いている位置へ移動
 *      FUNCTION: /  → A の位置,  - → Q の位置,  F6 → N の位置
 *      NUM     : =  → 左親指2番目(Win),  _ → 左親指3番目(Alt)
 *      layer_6 : ブートローダー → N の位置
 *  - Bluetooth関連キー(layer_6)は有線のため、トラックボール設定キーに置き換え
 *  - ロータリーエンコーダーは無いので省略
 *
 * レイヤー: 0 BASE / 1 FUNCTION / 2 NUM / 3 ARROW / 4 MOUSE(自動) / 5 SCROLL / 6 SYSTEM / 7 空き
 */

#include QMK_KEYBOARD_H
#include "quantum.h"

enum layers { _BASE = 0, _FUNC, _NUM, _ARROW, _MOUSE, _SCROLL, _SYS, _L7 };

// ---- タップダンス: 1回=英数(LANG2) / 2回=かな(LANG1) ----
enum { TD_IME = 0 };
tap_dance_action_t tap_dance_actions[] = {
    [TD_IME] = ACTION_TAP_DANCE_DOUBLE(KC_LNG2, KC_LNG1),
};

// ---- roBaのモッドタップ・レイヤータップ ----
#define GUI_S  LGUI_T(KC_S)
#define ALT_D  LALT_T(KC_D)
#define SFT_F  LSFT_T(KC_F)
#define SFT_J  RSFT_T(KC_J)
#define ALT_K  RALT_T(KC_K)
#define GUI_L  LGUI_T(KC_L)
#define SFT_Z  LSFT_T(KC_Z)
#define SCR_I  LT(_SCROLL, KC_I)
#define SPC_L2 LT(_NUM, KC_SPC)
#define CTL_TB LCTL_T(KC_TAB)
#define ENT_L1 LT(_FUNC, KC_ENT)
// roBaの lt_to_layer_0: 長押し=layer_6, タップ=レイヤー0に戻って「変換」
#define L6_HEN LT(_SYS, KC_INT4)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_universal(
    KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                        KC_Y    , KC_U    , SCR_I   , KC_O    , KC_P    ,
    KC_A    , GUI_S   , ALT_D   , SFT_F   , KC_G    ,                        KC_H    , SFT_J   , ALT_K   , GUI_L   , KC_QUOT ,
    SFT_Z   , KC_X    , KC_C    , KC_V    , KC_B    ,                        KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH ,
    QK_GESC , KC_LGUI , KC_LALT , L6_HEN  , SPC_L2  , CTL_TB  ,    KC_BSPC , ENT_L1  , KC_NO   , KC_NO   , KC_NO   , TD(TD_IME)
  ),

  [_FUNC] = LAYOUT_universal(
    KC_MINS , KC_7    , KC_8    , KC_9    , KC_PERC ,                        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,
    KC_SLSH , LGUI_T(KC_4), LALT_T(KC_5), LSFT_T(KC_6), KC_ASTR ,            KC_F7   , KC_F8   , KC_UP   , KC_F9   , KC_F10  ,
    _______ , KC_1    , KC_2    , KC_3    , KC_PLUS ,                        KC_F6   , KC_LEFT , KC_DOWN , KC_RGHT , KC_F11  ,
    KC_DEL  , KC_0    , _______ , KC_DOT  , KC_EQL  , _______ ,    _______ , _______ , KC_NO   , KC_NO   , KC_NO   , KC_F12
  ),

  [_NUM] = LAYOUT_universal(
    KC_MINS , KC_P7   , KC_P8   , KC_P9   , S(KC_P5),                        KC_CIRC , KC_AMPR , KC_TILD , KC_LPRN , KC_RPRN ,
    KC_SLSH , KC_P4   , KC_P5   , KC_P6   , KC_ASTR ,                        KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,
    LSFT_T(KC_P0), KC_P1, KC_P2 , KC_P3   , KC_PLUS ,                        KC_LBRC , KC_RBRC , KC_LCBR , KC_RCBR , KC_BSLS ,
    KC_GRV  , KC_EQL  , KC_UNDS , KC_DOT  , _______ , _______ ,    _______ , _______ , KC_NO   , KC_NO   , KC_NO   , KC_PIPE
  ),

  [_ARROW] = LAYOUT_universal(
    KC_ESC  , C(S(KC_TAB)), KC_UP , C(KC_TAB), _______ ,                     _______ , _______ , _______ , _______ , _______ ,
    KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_END  ,                        _______ , _______ , _______ , _______ , _______ ,
    KC_LSFT , G(S(KC_LEFT)), _______, G(S(KC_RGHT)), _______ ,               _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,    _______ , _______ , KC_NO   , KC_NO   , KC_NO   , _______
  ),

  [_MOUSE] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                        _______ , KC_BTN1 , MO(_SCROLL), KC_BTN2, _______ ,
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,    _______ , _______ , KC_NO   , KC_NO   , KC_NO   , _______
  ),

  [_SCROLL] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,    _______ , _______ , KC_NO   , KC_NO   , KC_NO   , _______
  ),

  [_SYS] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                        CPI_D100, CPI_I100, SCRL_DVD, SCRL_DVI, KBC_SAVE,
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , KC_1    , KC_2    , KC_3    , _______ ,                        QK_BOOT , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,    _______ , _______ , KC_NO   , KC_NO   , KC_NO   , _______
  ),

  [_L7] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,    _______ , _______ , KC_NO   , KC_NO   , KC_NO   , _______
  ),
};
// clang-format on

// ---- コンボ（roBaの同時押し + 中央4キーの代用） ----
const uint16_t PROGMEM cmb_eisu[]  = {ALT_D, SFT_F, COMBO_END};   // D+F = 英数
const uint16_t PROGMEM cmb_kana[]  = {SFT_J, ALT_K, COMBO_END};   // J+K = かな
const uint16_t PROGMEM cmb_dquo[]  = {GUI_L, KC_QUOT, COMBO_END}; // L+' = "
const uint16_t PROGMEM cmb_snip[]  = {SFT_F, KC_G, COMBO_END};    // F+G = Win+Shift+S
const uint16_t PROGMEM cmb_mins[]  = {KC_H, SFT_J, COMBO_END};    // H+J = -
const uint16_t PROGMEM cmb_coln[]  = {KC_V, KC_B, COMBO_END};     // V+B = :
const uint16_t PROGMEM cmb_scln[]  = {KC_N, KC_M, COMBO_END};     // N+M = ;

combo_t key_combos[] = {
    COMBO(cmb_eisu, KC_LNG2),
    COMBO(cmb_kana, KC_LNG1),
    COMBO(cmb_dquo, KC_DQUO),
    COMBO(cmb_snip, LSG(KC_S)),
    COMBO(cmb_mins, KC_MINS),
    COMBO(cmb_coln, KC_COLN),
    COMBO(cmb_scln, KC_SCLN),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // lt_to_layer_0 のタップ動作: レイヤー0へ戻してから「変換」を送る
    if (keycode == L6_HEN && record->tap.count) {
        if (record->event.pressed) {
            layer_move(_BASE);
            tap_code(KC_INT4);
        }
        return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // SCROLLレイヤー(5)が最上位のときはトラックボールでスクロール
    keyball_set_scroll_mode(get_highest_layer(state) == _SCROLL);
    return state;
}

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
