// SPDX-License-Identifier: GPL-2.0

#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

void some_kfunc(void) __ksym;

SEC("xdp")
int handler2(struct xdp_md* xdp) {
  some_kfunc();
  return 0;
}
