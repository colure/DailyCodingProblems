<?php

$result='';
$firstNum;
$secondNum;
$errors = array('firstNum'=>'','secondNum'=>'');

if(isset($_POST['submit'])){
    //input error checking
    if(empty($_POST['sumNum'])){
        $errors['firstNum']= 'A [k] number is required.<br />';
    } else {
        $firstNum = $_POST['sumNum'];
        if(!preg_match('/^[0-9]+$/', $firstNum)){
            $errors['firstNum'] = 'A [k] number should be digits only.<br/>';
        }
    }
    if(empty($_POST['numList'])){
        $errors['secondNum'] = 'At least one number is required.<br />';
      } else {
        $secondNum = $_POST['numList'];
        if(!preg_match('/^([0-9\s]+)(,\s*[0-9\s]*)*$/', $secondNum)){
        $errors['secondNum'] = 'Numbers must be a comma separated list of digits only.';
        }
    }

    if(!array_filter($errors)){
        $numSumFlag = False;
        $numSum = intval(htmlspecialchars($_POST['sumNum']));
        $numArray = explode(',', $_POST['numList']);
        foreach($numArray as $num){
            $cleanNumArray[] = intval(htmlspecialchars(trim($num)));
        }
        
        for($i = 0; $i < count($cleanNumArray); $i++){
            if(in_array(($numSum - $cleanNumArray[$i]), $cleanNumArray)){
                $numSumFlag=True;
            }
        }
        if($numSumFlag){
            $result= 'Two of the numbers in ' . htmlspecialchars($_POST['numList']) . ' add to be ' . htmlspecialchars($_POST['sumNum']) . '.<br/>';
        } else {
            $result= 'Two of the numbers in ' . htmlspecialchars($_POST['numList']) . ' do not add to be ' . htmlspecialchars($_POST['sumNum']) . '.<br/>';
        }
    }
}


?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-giJF6kkoqNQ00vy+HMDP7azOuL0xtbfIcaT9wjKHr8RbDVddVHyTfAAsrekwKmP1" crossorigin="anonymous">
    <link rel="stylesheet" href="styles.css">
    <title>Daily Coding Problems: 001</title>
</head>
<body>
<div class="container">
        <div class="row justify-content-md-center">
            <div class="col-lg-6">
            <h1 class="text-center my-4">Daily Coding Problems:</h1>
            <h3 class="text-center text-muted">001</h3>
            <p>Given a list of numbers and a number k, return whether any two numbers from the list add up to k.</p>
            <p>For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.</p>
            </div>
        </div>
    
        <div class="row justify-content-md-center mt-4">
            <div class="col-lg-4">
                <form action="<?php echo $_SERVER['PHP_SELF']?>" method="POST">
                    <label class="form-label">Enter a number [k]:</label>
                    <input type="text" class="form-control" name="sumNum" value="<?php echo htmlspecialchars($_POST['sumNum']) ?? '' ?>">
                    <div class="text-danger p-2">
                    <?php echo $errors['firstNum']; ?>
                    </div>
                    <label class="form-label">Enter a list of comma separated numbers:</label>
                    <input type="text" class="form-control" name="numList" value="<?php echo htmlspecialchars($_POST['numList']) ?? '' ?>">
                    <div class="text-danger p-2">
                    <?php echo $errors['secondNum']; ?>
                    </div>
                    <input type="submit" name="submit" value="Submit" class="btn btn-secondary mt-4" role="button">
                </form>
            </div>
            <?php if(isset($_POST['submit']) && (!array_filter($errors))){ ?>
                <div class="alert alert-primary my-3">
                <?php echo $result; ?>
                </div>
            <?php } ?>
        </div>
    
    </div>

    
</body>
</html>
