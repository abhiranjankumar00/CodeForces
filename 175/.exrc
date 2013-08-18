if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
let &cpo=s:cpo_save
unlet s:cpo_save
set autowrite
set background=dark
set backspace=indent,eol,start
set cindent
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set hidden
set ignorecase
set incsearch
set makeprg=if\ [\ -f\ \"Makefile\"\ ];then\ make\ $*;else\ if\ [\ -f\ \"makefile\"\ ];then\ make\ $*;else\ g++\ -O2\ -g\ -std=c++0x\ -Wno-unused-result\ -D_GLIBCXX_DEBUG\ %;fi;fi
set printdevice=pdf
set printoptions=paper:A4,syntax:y,wrap:y
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set smartcase
set smartindent
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set wildmenu
" vim: set ft=vim :
