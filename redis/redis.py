import redis

def demo():
    print('hello, redis')
    
def main():
    # Redis default port is 6379
    # Redis default supports 16 databases
    client = redis.Redis(host='localhost', port=6379, db=0)

    client.set('foo', 'bar')

    value = client.get('foo')
    if value is None:
        print('The key "foo" does not exist')
    else:
        print(f'The value of "foo" is: {value.decode("utf-8")}')

if __name__ == '__main__':
    main()
