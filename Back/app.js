const express = require('express');
const bodyParser = require('body-parser');
const calculateRoute = require('./routes/calculator');
const path = require('path');
const cors = require('cors');
const app = express();

app.use(bodyParser.json());
app.use(cors());

// Serve frontend static files from the 'frontend' directory
app.use(express.static(path.join(__dirname, '../frontend')));

app.use('/calculate', calculateRoute);

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});