from pet3 import Pet

p = Pet()
p.name = "Charly"  # OK, overwrite value in C++
p.age = 2  # OK, dynamically add a new attribute
p.__dict__  # just like a native Python class
print(f"{p.age=}", f"{p.name=}", f"{p.__dict__=}")
