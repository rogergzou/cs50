<table>
    <?php
        
        foreach ($positions as $position)
        {
            print("<tr>");
            print("<td>{$position["symbol"]}</td>");
            print("<td>{$position["time"]}</td>");
            print("<td>{$position["type"]}</td>");
            print("<td>{$position["shares"]}</td>");
            print("<td>{$position["price"]}</td>");
            print("</tr><br/>");
        }

    ?>
</table>
<br/>
<p>Cash = <?= $cash["cash"] ?></p>
