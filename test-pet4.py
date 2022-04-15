from pet4 import Pet, Dog
d = Dog('Jack')
p = Pet('Joe')
print(d,p, 'dog is a subclass of pet?:', issubclass(d.__class__, p.__class__))
