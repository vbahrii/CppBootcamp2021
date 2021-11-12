

def add_digits(number):
    digits = []
    while number > 0:
        digits.append(number % 10)
        number = number // 10
    result = 0
    for digit in digits:
        result = result + digit
    if result > 9:
        result = add_digits(result)
    return result

def effective_add_digits(number):
    candidate = number % 9
    if candidate == 0:
        return 9
    return candidate

for i in range (1,1000000):
    #print(i, " ", add_digits(i), " ", i%9)
    assert add_digits(i) == effective_add_digits(i)
