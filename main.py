import timeit

def iterative_power_d(base, exponent):
    ret_val = 1.0
    if exponent < 0:
        return 1.0 / iterative_power_d(base, -exponent)
    else:
        for i in range(exponent):
            ret_val *= base
    return ret_val

def recursive_power_d(base, exponent):
    if exponent < 0:
        return 1.0 / recursive_power_d(base, -exponent)
    elif exponent == 0:
        return 1.0
    else:
        return base * recursive_power_d(base, exponent - 1)

def iterative_power_int(base, exponent):
    ret_val = 1.0
    if exponent < 0:
        return 1.0 / iterative_power_int(base, -exponent)
    else:
        for i in range(exponent):
            ret_val *= base
    return ret_val

def recursive_power_int(base, exponent):
    ret_val = 1.0
    if exponent < 0:
        return 1.0 / recursive_power_int(base, -exponent)
    elif exponent == 0:
        return 1.0
    else:
        return base * recursive_power_int(base, exponent - 1)

def measure_time(n, output_file):
    doub_base = 3.14159265359
    i_base = 131071

    start_first = timeit.default_timer()
    iterative_power_d(doub_base, n)
    stop_first = timeit.default_timer()
    duration_first = (stop_first - start_first) * 1e9  # Convert to nanoseconds

    start_second = timeit.default_timer()
    recursive_power_d(doub_base, n)
    stop_second = timeit.default_timer()
    duration_second = (stop_second - start_second) * 1e9

    start_third = timeit.default_timer()
    iterative_power_int(i_base, n)
    stop_third = timeit.default_timer()
    duration_third = (stop_third - start_third) * 1e9

    start_fourth = timeit.default_timer()
    recursive_power_int(i_base, n)
    stop_fourth = timeit.default_timer()
    duration_fourth = (stop_fourth - start_fourth) * 1e9

    output_file.write(f"{n}, {duration_first}, {duration_second}, {duration_third}, {duration_fourth}\n")

def main():
    with open("results.csv", "w") as output_file:
        for i in range(997):
            measure_time(i, output_file)

if __name__ == "__main__":
    main()
