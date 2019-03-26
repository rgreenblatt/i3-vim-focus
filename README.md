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

Finally, this project needs to be installed as a vim plugin.
