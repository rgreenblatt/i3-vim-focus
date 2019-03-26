Vim plugin for seamless i3/vim navigation
=========================================

Allows i3 direction keys to control vim splits and i3 windows seamlessly

Requires the use of keyboard remapping like https://github.com/rgreenblatt/keyboard

The following should be added to your `~/.vimrc` / `init.nvim`

```viml
map gzl :call Focus('right', 'l')<CR>
map gzh :call Focus('left', 'h')<CR>
map gzk :call Focus('up', 'k')<CR>
map gzj :call Focus('down', 'j')<CR>
```

The i3 config needs to be updated with the following bindings.

```
bindsym $mod+h exec "i3-vim-focus left"
bindsym $mod+j exec "i3-vim-focus down"
bindsym $mod+k exec "i3-vim-focus up"
bindsym $mod+l exec "i3-vim-focus right"
```

Finally, this project needs to be installed as a vim plugin.
