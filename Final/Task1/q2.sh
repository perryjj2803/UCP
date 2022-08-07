#!/bin/bash

grep -E [^AB] name.txt | grep "^.\{0,5\}$"