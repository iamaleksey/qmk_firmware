#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 175

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// 1Khz polling rate
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4 
