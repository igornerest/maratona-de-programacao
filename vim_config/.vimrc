set number        
set showmatch        
set background=dark
 
syntax on
colorscheme desert

set autoindent        
set shiftwidth=4
set softtabstop=4
set tabstop=4
set expandtab
set relativenumber

nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

au BufNewFile ~/*.cpp 0r ~/.base.cpp