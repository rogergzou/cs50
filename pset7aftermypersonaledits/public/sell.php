<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // if (empty($_POST["symbol"]) || empty($_POST["shares"]))
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a stock ticker symbol and the amount sold.");
        }
        
        else
        {
            // require("../includes/functions.php");
            // $cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            $rows = query("SELECT id, symbol, shares FROM stock_list WHERE id = ?", $_SESSION["id"]);
            $_POST["symbol"] = strtoupper($_POST["symbol"]);
            $stock = lookup($_POST["symbol"]);
            if ($stock === false)
            {
                apologize("Symbol lookup failed, sorry. Was it a valid symbol?");           
            }//6764.8560
            // $positions = [];
            $idz = $_SESSION["id"];
            foreach ($rows as $row)
            { //6764.8560
                // $stock = lookup($row["symbol"]);
                if ($_POST["symbol"] == $row["symbol"])
                {
                    /*if ($sharez < $row["shares"])
                    {
                        if (query("UPDATE stock_list SET shares = shares - $sharez WHERE id =?", $_SESSION["id"] . " AND symbol =?", $_POST["symbol"])===false)
                        {
                            apologize("Update didn't work :(");
                        }
                    }*/
                    if (false)
                    {
                    }
                    else
                    {
                        if (query("DELETE FROM stock_list WHERE id = $idz AND symbol =?", $_POST["symbol"])===false)
                        {
                            apologize("Delete didn't work :(");
                        }
                        
                        else if (query("INSERT INTO history (time, type, symbol, shares, price, id) VALUES (NOW(), 'sell', ?, ?, ?, ?)", $_POST["symbol"],
                            $row["shares"], $stock["price"], $_SESSION["id"])===false)
                        {
                            apologize("Unable to load into history");
                        }
                    }
                    $sharez = $row["shares"];
                    $stock["price"] = number_format($stock["price"], 4);
                    // dump($sharez);
                    $cash = $sharez * $stock["price"];
                    //10192.9200
                    //dump($stock["price"]);
                    
                    if (query("UPDATE users SET cash = cash + '$cash' WHERE id =?", $_SESSION["id"]) === false)
                    {
                        apologize("Could not update cash sorry :(");
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
                }
                
            }

            
                
            // require("../templates/header.php");
            // render("../templates/quote_display.php", ["symbol" => $stock["symbol"]], ["name" => $stock["name"]], ["price" => $stock["price"]]);
            redirect("index.php");
            //require("../templates/footer.php");
            
        }
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
        render("sell_form.php", ["title" => "Sell"]);
    }

?>
