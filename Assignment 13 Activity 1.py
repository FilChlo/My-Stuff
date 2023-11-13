# This program is used to ask the user for their name -
# - and rearrange their name in 'lastname, first initial.'
def get_name():
    print("Enter your first and last name.")
    name = input()
    name = " ".join(name.split())
    return name


def process_last(name):
    index = name.find(" ")
    if index < 0:
        last = ""
    else:
        last = name[:index]
    return last


def process_first(name):
    index = name.find(" ")
    if index < 0:
        first = ""
    else:
        first = name[index:]
        first = first.strip()
    return first


def display_result(last, first):
    print(f"You are {first}" + ", " + f"{last[0:1]}" + ".")


def main():
    name = get_name()
    last = process_last(name)
    first = process_first(name)
    display_result(last, first)
    
    
main()