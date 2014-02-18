<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]) || empty($_POST["shares"]))
        {
            apologize("You must provide a stock ticker symbol and the amount bought.");
        }
        
        else
        {
            if (preg_match("/^\d+$/", $_POST["shares"]) != true)
            {
                apologize("Please use an integer for shares");
            }
            $_POST["symbol"] = strtoupper($_POST["symbol"]);
            $usrcash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            
            $stock = lookup($_POST["symbol"]);
            
            if ($stock === false)
            {
                apologize("Symbol lookup failed, sorry. Was it a valid symbol?");           
            }
            $sharez = $_POST["shares"];
            $idz = $_SESSION["id"];
            $cash = $sharez * $stock["price"];
            // $cash = number_format($cash, 4);
            $usrcash = $usrcash[0]["cash"];
            if ($usrcash * 1000 < $cash * 1000)
            {
                apologize("Sorry not enough monies in da bank :(");
            }
            else if (query("UPDATE users SET cash = cash - ? WHERE id =?", $cash, $_SESSION["id"]) === false)
            {
                apologize("Could not update cash sorry :(");
            }
            else if (query("INSERT INTO stock_list (id, symbol, shares) VALUES (?, ?, ?) 
                ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], $_POST["symbol"], $sharez , $sharez)===false)
            {
                apologize("Insert didn't work :(");
            }
            
            if (query("INSERT INTO history (time, type, symbol, shares, price, id) VALUES (NOW(), 'buy', ?, ?, ?, ?)", $_POST["symbol"],
                $_POST["shares"], $stock["price"], $_SESSION["id"])===false)
            {
                apologize("Unable to load into history");
            }
            
            redirect("index.php");
            }
            /*
            
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];*/
            // array_push($positions, $position);
            // $positions[$row["symbol"]] = $position; 
        // render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);
        
        
    

        
            
            // require("../templates/header.php");
            // render("../templates/quote_display.php", ["symbol" => $stock["symbol"]], ["name" => $stock["name"]], ["price" => $stock["price"]]);
            
            //require("../templates/footer.php");
        
        
        // assumes query worked and no errors found. also that elif executed query insert
        /*else
        {
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            
            // remember that user's now logged in by storing user's ID in session
            $_SESSION["id"] = $id;
            // require("login.php");
            // redirect to portfolio
            redirect("index.php");
        }*/
    }
    else
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }
//preg_match("/^\d+$/", $_POST["shares"])
?>


