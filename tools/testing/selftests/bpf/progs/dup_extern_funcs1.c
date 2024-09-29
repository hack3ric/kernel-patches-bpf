// SPDX-License-Identifier: GPL-2.0

#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

char _license[] SEC("license") = "GPL";

void some_kfunc(void) __ksym;

SEC("tc")
int handler1(struct __sk_buff* skb) {
  some_kfunc();
  return 0;
}
