#!/bin/bash
echo $1
case $1 in
	"hello")
		echo hello world
		;;
	"rao")
		echo rao world
		;;
	*)
		echo other world
		;;
esac
