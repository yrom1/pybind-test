from pet4 import Pet, Dog
d = Dog('Jack')
p = Pet('Joe')
print(d,p, 'dog is a subclass of pet?:', issubclass(d.__class__, p.__class__))

def try_bark(obj):
    try:
        print('barking with object', obj, 'of type', type(obj),  obj.bark())
    except:
        print('failed to bark with object:', obj, 'of type:', type(obj))

(try_bark(x) for x in (d,p))
