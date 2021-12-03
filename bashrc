
function git_branch {
	branch="`git branch 2>/dev/null | grep "^\*" | sed -e "s/^\*\ //"`"
	if [ "${branch}" != "" ];then
		if [ "${branch}" = "(no branch)" ];then
			branch="(`git rev-parse --short HEAD`...)"
		fi
		echo " ($branch)"
	fi
}

export PS1="\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$(git_branch)$ "
