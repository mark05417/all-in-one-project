# (1) decorator
def use_logging(func):
    def wrapper():
        print("%s is running" % func.__name__)
        return func()
    return wrapper

@use_logging  # foo() <- use_logging(foo)
def foo():
    print('i am foo')

foo()

# (2) decorator with function parameter
def use_logging2(func):
    def wrapper(*args, **kwargs):
        print("%s is running" % func.__name__)
        return func(*args, **kwargs)
    return wrapper

@use_logging2 # bar() <- use_logging2(bar)
def bar(name, age=None, height=None):
    print("I am bar, name %s, age %s, height %s" % (name, age, height))

bar("aaa", age=10, height=100)

# (3) decorator with parameter
def use_logging3(level):
    def decorator(func):
        def wrapper():
            if level == "warn":
                print("warn: %s is running" % func.__name__)
            elif level == "info":
                print("info: %s is running" % func.__name__)
            return func()
        return wrapper

    return decorator

@use_logging3(level="warn") # @use_logging3(level="warn") <- @decorator,  baz() <- decorator(baz)
def baz():
    print("i am baz")

baz()

# (4) class decorator
class Foo(object):
    def __init__(self, func):
        self._func = func

    def __call__(self):
        print ('class decorator runing')
        self._func()
        print ('class decorator ending')

@Foo
def qux():
    print ('qux')

qux()

# (5) order of decorator
def a(func):
    def wrapper():
        print("a is running")
        return func()
    return wrapper

def b(func):
    def wrapper():
        print("b is running")
        return func()
    return wrapper

@a
@b
def c():
    print("c is running")

c()