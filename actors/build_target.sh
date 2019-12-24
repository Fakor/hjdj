#!/usr/bin/env bash

TARGET=$1

g++ $TARGET -Istatic/include -Llib -lhjdj
