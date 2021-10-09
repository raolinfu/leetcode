set nu
set ts=4
set autoindent
set splitbelow splitright
set nocompatible
set hidden
set encoding=utf-8
set completeopt-=preview
set shiftwidth=4
" Current line
set statusline=%l
" Separator
set statusline+=/
" Total lines
set statusline+=%L

let mapleader = " "

map <Leader>qq	:q<CR>
map <Leader>ww 	:w<CR>
map <Leader>wq 	:wq<CR>
map <Leader>qa 	:qa<CR>
map <Leader>qf	:qa!<CR>

" Remap splits navigation to just CTRL + hjkl
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l

" Resize
nnoremap <silent> <C-Left> :vertical resize +3<CR>
nnoremap <silent> <C-Right> :vertical resize -3<CR>
nnoremap <silent> <C-Up> :resize +3<CR>
nnoremap <silent> <C-Down> :resize -3<CR>

map <Leader>tt :vert ter<CR>
map <Leader>rr :terminal<CR>

map <Leader>th <C-w>t<C-w>H
map <Leader>tk <C-w>t<C-w>K

map <Leader>y "+y 
map <Leader>p "+p
map <Leader>d "+d
" for ctags
nnoremap <Leader>jj <C-]>
nnoremap <Leader>bj <C-t>
nnoremap <Leader>bb <C-b>
nnoremap <Leader>ff <C-f>
 
" for ycm
nmap <Leader>fw <Plug>(YCMFindSymbolInWorkspace)
nmap <Leader>fs <Plug>(YCMFindSymbolInDocument)
let g:ycm_confirm_extra_conf = 1

nnoremap <Leader>z 0
nnoremap <Leader>m $
nnoremap <Leader>f F
nnoremap <Leader>r R
nnoremap <Leader><tab> mqI<tab><esc>'q
inoremap hh <Left>
inoremap jj <Down>
inoremap kk <Up>
inoremap ll <Right>
" map insert mode
inoremap jk <esc>
" inoremap <C-d> <esc>ddi
nnoremap <Leader>; mqA;<esc>`q

au BufReadPost * if line("'\"") > 0 | if line("'\"") <= line("$") | exe("norm '\"") | else |exe "norm $"| endif | endif
" filetype off " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')
" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'vim-ctrlspace/vim-ctrlspace'
Plugin 'preservim/nerdtree'
" Keep Plugin commands between vundle#begin/end.
" All of your Plugins must be added before the following line
call vundle#end() " required
filetype plugin indent on " required

:nnoremap <leader>sv :source $MYVIMRC<cr>

" Start NERDTree and leave the cursor in it.
" autocmd VimEnter * NERDTree
nnoremap <leader>n :NERDTreeFocus<CR>

