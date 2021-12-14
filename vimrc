set tabstop=4
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
:let mapleader = " "
inoremap jk <esc>
nnoremap <Leader>q :q<CR>
nnoremap <Leader>w :w<CR>
nnoremap <Leader>z 0
nnoremap <Leader>m $

" 设置缩写
iabbrev imain int main(){<cr>return 0;<cr>}<esc>kkA

onoremap p i(
onoremap b i{
onoremap s i[

" map <Leader>wq	:wq<CR>
" map <Leader>qa	:qa<CR>
" map <Leader>qf	:qa!<CR>

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
" inoremap hh <Left>
" inoremap jj <Down>
" inoremap kk <Up>
" inoremap ll <Right>
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
Plugin 'preservim/nerdcommenter'
Plugin 'Chiel92/vim-autoformat'
" Plugin 'wxnacy/vim-mysql'
" Keep Plugin commands between vundle#begin/end.
call vundle#end() " required
filetype plugin indent on " required

:nnoremap <leader>sv :source $MYVIMRC<cr>
nnoremap <leader>n :NERDTreeFocus<CR>
:nnoremap <leader>sv :source $MYVIMRC<cr>

" Start NERDTree and leave the cursor in it.
" autocmd VimEnter * NERDTree
nnoremap <leader>n :NERDTreeFocus<CR>


" Create default mappings
let g:NERDCreateDefaultMappings = 1

" Add spaces after comment delimiters by default
let g:NERDSpaceDelims = 1

" Use compact syntax for prettified multi-line comments
let g:NERDCompactSexyComs = 1

" Align line-wise comment delimiters flush left instead of following code indentation
let g:NERDDefaultAlign = 'left'

" Set a language to use its alternate delimiters by default
let g:NERDAltDelims_java = 1

" Add your own custom formats or override the defaults
let g:NERDCustomDelimiters = { 'c': { 'left':'//','leftAlt':'/**','rightAlt':"*/" } }

" Allow commenting and inverting empty lines (useful when commenting a region)
let g:NERDCommentEmptyLines = 1

" Enable trimming of trailing whitespace when uncommenting
let g:NERDTrimTrailingWhitespace = 1

" Enable NERDCommenterToggle to check all selected lines is commented or not
let g:NERDToggleCheckAllLines = 1

" for autoformat
noremap <F3> :Autoformat<CR>
" au BufWrite * :Autoformat

