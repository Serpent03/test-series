def multiply(num1: str, num2: str) -> str:
    n1, n2 = 0, 0

    for char in num1:
        n1 *= 10
        n1 += ord(char) - 48
        
    for char in num2:
        n2 *= 10
        n2 += ord(char) - 48

    return f"{n1 * n2}"