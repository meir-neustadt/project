let display = document.getElementById("display");


function clearDisplay() {
    display.value = "";
}

function eraseOneLeft() {
    display.value = display.value.slice(0, -1);
}

function press(value) {
    // Get the current cursor position
    let cursorPos = display.selectionStart;
    
    // Get the text before and after the cursor
    let beforeCursor = display.value.slice(0, cursorPos);
    let afterCursor = display.value.slice(cursorPos);

    // Insert the value at the cursor position
    display.value = beforeCursor + value + afterCursor;
    
    // Move the cursor to the right of the inserted value
    cursorPos += value.length;

    // Update the cursor position and refocus the input
    setTimeout(() => {
        display.setSelectionRange(cursorPos, cursorPos);
        display.focus();
    }, 0);
}


function moveOneLeft() {
    let cursorPos = display.selectionStart;

    // Move the cursor one position to the left if it's not at the beginning
    if (cursorPos > 0) {
        display.setSelectionRange(cursorPos - 1, cursorPos - 1);
    }

    // Focus the input field to ensure the cursor is visible
    display.focus();
}

function calculate() {
    fetch("http://localhost:3000/calculate", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({ expression: display.value })
    })
    .then(response => response.json())
    .then(data => {
        if (data.error) {
            display.value = "Error";
        } else {
            display.value = data.result;
        }
    })
    .catch(error => {
        display.value = "Error";
        console.error("Error:", error);
    });
}
