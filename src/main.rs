use nom::{
    bytes::complete::tag,
    character::complete::{alphanumeric1 as alphanumeric, multispace1 as multispace},
    sequence::{preceded, tuple},
    IResult,
};
use std::fs;

#[derive(Debug)]
struct Record {
    field1: String,
    field2: String,
    field3: String,
    field4: String,
    field5: String,
    field6: String,
    field7: String,
    field8: String,
    field9: String,
    // Add more fields as per your CSV structure
}

fn parse_line(input: &str) -> IResult<&str, Record> {
    let (input, (field1, _, field2)) = tuple((alphanumeric, tag(","), alphanumeric))(input)?;
    Ok((input, Record { field1: field1.to_string(), field2: field2.to_string(),field3: field3.to_string(),field4: field4.to_string(),field5: field5.to_string(),field6: field6.to_string(),field7: field7.to_string(),field8: field8.to_string(),field9: field9.to_string() }))
}

fn main() {
    let data = fs::read_to_string("src/path_to_your_file.csv").expect("Unable to read file");
    let lines: Vec<&str> = data.lines().collect();
    for line in lines {
        match parse_line(line) {
            Ok((_, record)) => println!("{:?}", record),
            Err(err) => eprintln!("Error: {:?}", err),
        }
    }
}
