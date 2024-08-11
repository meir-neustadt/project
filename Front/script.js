let display = document.getElementById("display");

function press(value) {
    display.value += value;
}

function clearDisplay() {
    display.value = "";
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
