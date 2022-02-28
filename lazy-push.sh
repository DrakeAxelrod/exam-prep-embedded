#!/usr/bin/env bash
BASEDIR=$(dirname "$0")
echo "$BASEDIR"
cd $BASEDIR
git add .
git commit -m "default"
git push