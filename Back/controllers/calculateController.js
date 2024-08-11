const { exec } = require('child_process');
const path = require('path');

exports.calculate = (req, res) => {
    console.log('calc');    
    const expression = req.body.expression;
    console.log(expression);

    const calculatorPath = path.join(__dirname, '../cpp/calculator'); // Use absolute path for clarity

    exec(`${calculatorPath} "${expression}"`, (error, stdout, stderr) => {
        if (error) {
            console.log(111111,error);
            
            return res.status(500).json({ error: stderr });
        }
        console.log(2222222, stdout);
        
        res.json({ result: stdout.trim() });
    });
};
