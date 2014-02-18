<?php

    // configuration
    require_once("../includes/config.php"); 
    
    require("../templates/buttons.php");
    /*
    $cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $rows = query("SELECT symbol, shares FROM stock_list WHERE id = ?", $_SESSION["id"]);
    $positions = [];
    // $in = 1;
    foreach ($cash as $row)
    {
        $cash = $row;
    }
    
    
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
  */          
            /*if (array_push($positions, $position) == 0)
            {
                apologize("array push failed wtf idk why");
            }*/
            /*
            // $positions["$in"] = $position;
            // $in++;
            //$positions[$row["symbol"]] = $position; 
        // render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);
        }
        
    }
    //dump($positions);
    // render portfolio
  //  render("../templates/portfolio.php", ["positions" => $positions, "cash" => $cash, "title" => "Portfolio"]);
*/
?>

hi
