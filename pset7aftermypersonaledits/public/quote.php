<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a stock ticker symbol.");
        }
        
        else
        {
            // require("../includes/functions.php");
            $stock = lookup($_POST["symbol"]);
            if ($stock === false)
            {
                apologize("Symbol lookup failed, sorry. Was it a valid symbol?");           
            }
            else
            {
                $stock["price"] = number_format($stock["price"], 4);
                // require("../templates/header.php");
                // render("../templates/quote_display.php", ["symbol" => $stock["symbol"]], ["name" => $stock["name"]], ["price" => $stock["price"]]);
                render("../templates/quote_display.php", ["stock" => $stock]);
                //require("../templates/footer.php");
            }
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
        render("quote_form.php", ["title" => "Quote"]);
    }

?>
