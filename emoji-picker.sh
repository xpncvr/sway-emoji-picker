#!/usr/bin/env bash
EMOJI_FILE="emojis.txt"

if [[ ! -f "$EMOJI_FILE" ]]; then
    exit 1
fi

choice=$(cat "$EMOJI_FILE" | wmenu -i -l 6 -p "Emoji:")

if [[ -n "$choice" ]]; then
    emoji=$(echo "$choice" | awk '{print $1}')
    echo -n "$emoji" | wl-copy
fi
