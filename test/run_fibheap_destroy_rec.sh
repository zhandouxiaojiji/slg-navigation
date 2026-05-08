#!/usr/bin/env sh
set -eu

cd "$(dirname "$0")/.."

gcc -g3 -O0 -fsanitize=address -fno-omit-frame-pointer \
    -I. \
    -o /tmp/test_fibheap_destroy_rec \
    test/test_fibheap_destroy_rec.c fibheap.c -lm

/tmp/test_fibheap_destroy_rec
