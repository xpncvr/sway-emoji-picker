## An emoji picker for the Sway WM


A shell script that runs **wmenu** to display a searchable menu to find emoji. This will copy the emoji to your clipboard using **wl-clipboard** (make sure you have that installed)

</br>

<details>
  <summary>Preview</summary>
  <img width="707" height="346" alt="image" src="https://i.imgur.com/2o6x6Hj.png" />
</details>

</br>

### Usage
To use it just add the following line with the path to where you have the script installed. Make sure emojis.txt is in the same folder as the script

```
bindsym $mod+e exec /home/username/path/to/emoji-picker.sh
```

</br>

To update your emoji list run the following in the project folder:

```
curl https://unicode.org/Public/emoji/latest/emoji-test.txt -o emoji-test.txt
gcc pre-parse.c -o pre-parse && ./pre-parse
```
This will generate a new emojis.txt

