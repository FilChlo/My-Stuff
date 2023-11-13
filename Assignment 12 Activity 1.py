# Program is used to ask user for test scores and display the -
# - lowest, highest, and average of the scores.
def fixed_array():
    array = []
    print("Enter your grade scores. Enter negative when finished.")
    for index in range(1000):
        score = int(input())
        if score < 0:
            break
        array.append(score)
    return array


def total_scores(array):
    total = 0
    for index in range(len(array)):
        total += array[index]
    return total


def average_scores(total, array):
    average = total / len(array)
    return average


def display_result(array, average):
    print('The lowest score is ', min(array))
    print('The highest score is ', max(array))
    print('The average is ', average)


def main():
    array = fixed_array()
    total = total_scores(array)
    average = average_scores(total, array)
    display_result(array, average)


main()