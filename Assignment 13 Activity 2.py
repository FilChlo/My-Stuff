# This program is used to ask the user for a sentence -
# - and reverse the sentence order.
def get_text():
    print("Type in a sentence.")
    text = input()
    return text


def process_text(text):
    text = " ".join(text.split())
    reverse = ''.join(reversed(text))
    return reverse


def display_result(reverse):
    print("Here is the reverse: " f"{reverse}")


def main():
    text = get_text()
    reverse = process_text(text)
    display_result(reverse)
    

main()