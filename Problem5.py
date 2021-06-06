def cons(a, b): #emulates lisps cons package, cells used to hold ordered pairs
    def pair(f):
        return f(a, b)
    return pair

def car(cons): #first element, left half, Address part of register
    return cons(lambda a, b: a) #takes in a & b, returns anon fn, lambda is anon function, takes f

def cdr(cons): #second element, right half, Decrement part of register
    return cons(lambda a, b: b)

print(car(cons(3, 4))) #outputs the left first CAR element
print(cdr(cons(3, 4))) #outputs the right second CDR element
