def foo():
    print('abcdefghij')

if __name__ == '__main__':      # entrypoint
    
    print(foo)
    print(hex(id(foo)))

    foo()
    print(f'mi funcion se llama: {foo.__name__}')
