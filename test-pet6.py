from pet6 import Pet

def inspect_pet(p):
    print([f"{x=}" for x in (p.name, p.age)])

p = Pet("jack", 2)
inspect_pet(p)
p.set("john")
p.set(42)
inspect_pet(p)
