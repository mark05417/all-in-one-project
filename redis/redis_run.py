import redis

def reset(client):
    client.flushall()

def scan(client):
    _, keys = client.scan(0, match='*', count=10)
    print(keys)

def basic(client):
    client.set('foo', 'bar')

    value = client.get('foo')
    if value is None:
        print('The key "foo" does not exist')
    else:
        print(f'The value of "foo" is: {value}')

def hash(client):
    client.hset('myhash', 'field1', 'value1')
    client.hset('myhash', 'field2', 'value2')

    print(f'The value of "field1" is: {client.hget('myhash', 'field1')}')
    print(f'The value of "field2" is: {client.hget('myhash', 'field2')}')

def set(client):
    client.sadd('myset', 'value1')
    client.sadd('myset', 'value2')

    print(f'The value of "myset" is: {client.smembers('myset')}')

def ordered_set(client):
    client.zadd('myset', {'value1': 2})
    client.zadd('myset', {'value2': 1})

    print(f'The value of "myset" is: {client.zrange('myset', 0, -1)}')

def list(client):
    client.lpush('mylist', 'value1')
    client.lpush('mylist', 'value2')

    print(f'The value of "mylist" is: {client.lrange('mylist', 0, -1)}')

def ttl(client):
    client.set('mykey', 'value')
    client.expire('mykey', 10)
    client.ttl('mykey')

def pipeline(client):
    p = client.pipeline()
    p.set('mykey', 'value')
    p.expire('mykey', 10)
    p.ttl('mykey')
    p.execute()

def transaction(client):
    with client.pipeline() as p:
        p.set('mykey', 'value')
        p.expire('mykey', 10)
        p.ttl('mykey')
        p.execute()


def document_db(client):
    from redisearch import IndexDefinition, TextField, NumericField, TagField
    from redis.commands.search.indexDefinition import IndexDefinition, IndexType
    schema = (
        TextField("$.brand", as_name="brand"),
        TextField("$.model", as_name="model"),
        TextField("$.description", as_name="description"),
        NumericField("$.price", as_name="price"),
        TagField("$.condition", as_name="condition"),
    )
    index = client.ft("idx:bicycle")
    index.create_index(
        schema,
        definition=IndexDefinition(prefix=["bicycle:"], index_type=IndexType.JSON),
    )

def main():
    # Redis default port is 6379
    # Redis default supports 16 databases
    client = redis.Redis(host='localhost', port=6379, db=0, decode_responses=True)

    basic(client)
    hash(client)
    # document_db(client)

    scan(client)
    # reset(client)

if __name__ == '__main__':
    main()
