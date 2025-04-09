#!/usr/bin/expect -f

# Start the phonebook program
spawn ./phonebook

# Define an Expect procedure (like a function)
proc add_contact {first last nick phone secret} {
    expect "1. ADD"
    send "1\r"
    expect "First name:"
    send "$first\r"
    expect "Last name:"
    send "$last\r"
    expect "Nickname:"
    send "$nick\r"
    expect "Phone number:"
    send "$phone\r"
    expect "Dark Secret:"
    send "$secret\r"
    after 1000  # Delay to simulate human interaction
}

# Add multiple contacts
add_contact "Gabriela" "Avena" "gb" "123456789" "ola, mundo jahetru45"
expect "1. ADD"
send "2\r"
add_contact "Julio" "ALves" "ja" "729378934324" "Eh muito secreto esse segredo"
add_contact "Joao" "Fei" "Jaozin" "jashdas" "2387982"
expect "1. ADD"
send "2\r"
add_contact "Menina" "Bueda" "yue" "236" "asdf"
add_contact "lakhjsdlkash92863h" "asdhjksa" "asdjhkda" "asdouad" "adshjlasd"
expect "1. ADD"
send "2\r"
add_contact "asd" "asd" "asd" "asdasdf" "asdad"
add_contact "asdasd" "asdas" "asd" "asd" "asd"
expect "1. ADD"
send "2\r"
add_contact "Ney" "Mar" "Menino" "0128912" "Menino ney"
expect "1. ADD"
send "2\r"
after 2000

# Add one more contact
add_contact "Final" "Santos" "Santinho" "98278732" "sadSecret"

# Perform a final search
expect "1. ADD"
send "2\r"
after 2000  # Pause to view search results
add_contact "Leo" "Messi" "Brasil" "98278732" "sadSecret"
expect "1. ADD"
send "2\r"

# Exit the program
expect "1. ADD"
send "3\r"
expect eof
