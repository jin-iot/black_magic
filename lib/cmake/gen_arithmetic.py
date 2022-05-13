#!/usr/bin/python
import sys

file_path = sys.argv[1]
loop_num = int(sys.argv[2])

with open(file_path, "a") as f:
    for i in range(0, (loop_num + 1)):
        for j in range(0, (loop_num + 1)):
            f.write("#define ___snt_pp_add_impl_" + str(i) + "_" + str(j) + " " + str(i + j) + "\n")
    for i in range(0, (loop_num + 1)):
        for j in range(0, (loop_num + 1)):
            f.write("#define ___snt_pp_sub_impl_" + str(i) + "_" + str(j) + " " + str(i - j) + "\n")
    for i in range(0, (loop_num + 1)):
        for j in range(0, (loop_num + 1)):
            f.write("#define ___snt_pp_mul_impl_" + str(i) + "_" + str(j) + " " + str(i * j) + "\n")
    for i in range(0, (loop_num + 1)):
        for j in range(1, (loop_num + 1)):
            f.write("#define ___snt_pp_div_impl_" + str(i) + "_" + str(j) + " " + str(int(i / j)) + "\n")
    for i in range(0, 17):
        for j in range(0, 17):
            f.write("#define ___snt_pp_pow_impl_" + str(i) + "_" + str(j) + " " + str(i**j) + "\n")